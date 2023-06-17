#include <iostream>
#include <fstream>
#include <curl/curl.h>

// 回调函数，用于接收HTTP响应
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main()
{
    // 设置OpenAI API的访问凭证和相关参数
    std::string apiKey = "YOUR_API_KEY";
    std::string gptEndpoint = "https://api.openai.com/v1/engines/davinci-codex/completions";
    std::string prompt = "YOUR_PROMPT";
    std::string headers = "Content-Type: application/json";
    std::string data = "{\"prompt\": \"" + prompt + "\", \"max_tokens\": 100}";

    // 初始化cURL
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();

    // 设置cURL选项
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, gptEndpoint.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // 创建保存回答的string变量
        std::string response;

        // 设置接收回答的回调函数和回调函数参数
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // 发送HTTP请求
        CURLcode res = curl_easy_perform(curl);

        // 检查HTTP请求是否成功
        if (res != CURLE_OK)
        {
            std::cerr << "Failed to perform cURL request: " << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            // 将回答保存到本地的txt文件
            std::ofstream outputFile("response.txt");
            if (outputFile.is_open())
            {
                outputFile << response;
                outputFile.close();
                std::cout << "Response saved to response.txt" << std::endl;
            }
            else
            {
                std::cerr << "Failed to open output file" << std::endl;
            }
        }

        // 清理cURL资源
        curl_easy_cleanup(curl);
    }

    // 清理cURL全局资源
    curl_global_cleanup();

    return 0;
}

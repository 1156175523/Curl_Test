#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

int main()
{

    CURL* curl = NULL;
    CURLcode res;
    //1、创建句柄
    curl = curl_easy_init();
    if(curl == NULL)
    {
        printf("curl init error!\n");
        exit(1);
    }

    //2、给句柄设置一些参数
    res = curl_easy_setopt(curl,CURLOPT_URL,"http://www.baidu.com");
    if(res != CURLE_OK)
    {
        printf("curl setopt url error!\n");
        exit(1);
    }
    res = curl_easy_setopt(curl,CURLOPT_POST,0);
    if(res != CURLE_OK)
    {
        printf("curl setopt url error!\n");
        exit(1);
    }
    //3、将请求提交
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
    {
        printf("curl setopt url error!\n");
        exit(1);
    }

    //4、处理从服务器返回的数据
    //
    //

    //5、释放句柄
    curl_easy_cleanup(curl);


    return 0;
}

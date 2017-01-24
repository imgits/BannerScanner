// BannerScanner.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BannerScanner.h"
extern "C"
{
//#include <curl.h>
}
int Help()
{
	printf("BannerScanner masscan_output.lst threads timeout output\n");
	return 0;
}

int main(int argc, char** argv)
{
			// global libcurl initialisation
	//CURLcode ccCurlResult = curl_global_init(CURL_GLOBAL_WIN32);
	//if (ccCurlResult == 0)
	//{
	//	// start l		ibcurl easy session
	//	CURL* hCurl = curl_easy_init();
	//	if (hCurl)
	//	{
	//	}
	//}

	BannerScanner scanner;
	scanner.LoadScanItems(argv[1]);
	printf("Hello world");
    return 0;
}


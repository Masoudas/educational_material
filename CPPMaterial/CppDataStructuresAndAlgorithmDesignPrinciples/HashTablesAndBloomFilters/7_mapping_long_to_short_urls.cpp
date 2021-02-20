/**
* In this exercise, we'll create a program to implement a service similar to https://tinyurl.com/. It can take a 
* very long URL and map it to a small URL that is easy and convenient to share. Whenever we enter the short URL, 
* it should retrieve the original URL.
* 
* We want the following functionalities:
*	- Store the original and corresponding smaller URL provided by the user efficiently,
*	- Retrieve the original URL based on the given smaller URL if found; otherwise, return an error.
* 
* For this end, we use an unordered_map, which has the tiny_url as key, and the actual url as value. The insertion
* function gets the URL together with the tiny URL. If the tiny URL is absent, the find function throws an error.
* So notice that one thing that is common for throwing error is to return a pair (or an optional) instead of 
* actually throwing an exception.
*/
#include <unordered_map>
#include <string>
#include <optional>
#include <iostream>

using std::unordered_map;

struct tiny_url_database {
	using TinyURL = std::string;
	using URL = std::string;

	unordered_map<TinyURL, URL> map{};

	bool registerURL(const TinyURL& tiny_url, const URL& url) {
		if (map.contains(tiny_url)) return false;
		
		//map.insert(tiny_url, url); // Copies the paramters
		map.emplace(tiny_url, url); // Again, uses copy constructor by forwarding. Works despite being const,
									// because of using the copy constructor.
		// map[tiny_url] = url; Same as insertion
		return true;
	}

	bool registerURL(TinyURL&& tiny_url, URL&& url) {
		if (map.contains(tiny_url)) return false;

		map.emplace(std::move(tiny_url), std::move(url));
		return true;
	}

	std::optional<URL> fetchURL(const TinyURL& tiny_url) {
		if (!map.contains(tiny_url)) {};

		return { map[tiny_url] };
	}

	bool deregisterURL(const std::string& tiny_url) {
		return map.erase(tiny_url);	// zero is implicitly converted to false, positive numbers to true!
	}

	void printURLs() const
	{
		for (const auto& entry : map)
		{
			std::cout << entry.first << " -> " << entry.second << std::endl;
		}

		std::cout << std::endl;
	}
};

//int main()
//{
//	tiny_url_database service;
//
//	tiny_url_database::TinyURL tiny = "www.myGod.com";
//	tiny_url_database::TinyURL url = "www.I'veBeenShot.com";
//
//	service.registerURL(tiny, url);	// rvalue constructor takes precedence here!
//
//}
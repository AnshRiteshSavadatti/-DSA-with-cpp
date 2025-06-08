// #include <bits/stdc++.h>
// using namespace std;

// // Function to extract resource paths from a given request URL
// string extractResourcePath(const string &request) {
//     vector<string> parts;
//     stringstream ss(request);
//     string part;

//     // Split the request by '/'
//     while (getline(ss, part, '/')) {
//         parts.push_back(part);
//     }

//     vector<string> resources;
//     for (const string &p : parts) {
//         if(p.substr(0, 8) == "resource"){
//             resources.push_back(p);
//         }
//     }

//     if (!resources.empty()) {
//         string resource_path = resources[0]; // Start with the first resource
    
//         // Append the remaining resources with '/'
//         for (size_t i = 1; i < resources.size(); i++) {
//             resource_path += "/" + resources[i];
//         }
    
//         return resource_path;
//     }
    
//     return ""; // Return empty string if no resources found
    
// }

// // Comparator function for sorting resource paths
// bool compareResources(const string &a, const string &b) {
//     int countA = count(a.begin(), a.end(), '/');
//     int countB = count(b.begin(), b.end(), '/');
//     return (countA == countB) ? (a < b) : (countA < countB);
// }

// // Function to process a list of requests and return sorted resource paths
// vector<string> getResourceList(vector<string> &requests) {
//     vector<string> resource_list;

//     for (const string &request : requests) {
//         string resource_path = extractResourcePath(request);
//         if (!resource_path.empty()) {
//             resource_list.push_back(resource_path);
//         }
//     }

//     // Sort using the comparator function
//     sort(resource_list.begin(), resource_list.end(), compareResources);

//     return resource_list;
// }

// // Driver function
// int main() {
//     vector<string> requests = {
//         "https://api.example.com/resource324/resource249/resource949/resource501/resource516",
//         "https://api.example.com/resource324/resource249/resource949/resource501/resource516/",
//         "https://api.example.com/resource730/",
//         "https://api.example.com/resource173/d58/",
//         "https://api.example.com/random/data"
//     };

//     vector<string> result = getResourceList(requests);
    
//     for (const string &res : result) {
//         cout << res << endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

string extractResources(string resource){
    vector<string> path;
    stringstream ss(resource);
    string part;

    vector<string> parts;

    while(getline(ss, part, '/')){
        parts.push_back(part);
    }

    vector<string> resources;

    for(auto it : parts){
        if(it.substr(0, 8) == "resource"){
            
        }
    }

}
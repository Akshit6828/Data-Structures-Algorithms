vector<vector<string>> partitions = partition(s);

    for(auto str:partitions){
        for(auto s: str)
            cout<<s<<" ";
        printf("\n"); 
    }
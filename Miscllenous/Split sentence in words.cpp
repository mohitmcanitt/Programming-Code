vector<string> printVertically(string s) {
  
        char *token=strtok((char *)s.c_str()," ");
        vector<string>splitted_string;
        while(token!=NULL)
        {
            splitted_string.push_back(token);
            token=strtok(NULL," ");
        }
        return splitted_string;
  
    }
/*
INPUT:
"HOW ARE YOU"

OUTPUT
["HOW","ARE","YOU"]

*/

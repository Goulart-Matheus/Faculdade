int strStr(char* haystack, char* needle) {
    if(strstr(haystack, needle)){
        char *result = strstr(haystack, needle);
        int k = result - haystack;
                return k;
    }

    return -1;
    
}
int lengthOfLastWord(char* s) {

    char *delim = " ";
    char *token; 
    int k = 0;

    token = strtok(s, delim);
    while(token != NULL){
        k = strlen(token);
        token = strtok(NULL, delim);
    }    
    return k;
}
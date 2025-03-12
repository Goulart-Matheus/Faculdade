char* truncateSentence(char* s, int k) 
{
int i = 0, j = 0, l = 0;
    
    while(l < k)
    { 
        while(s[i] != ' ' && i < strlen(s))
            {
                s[j++] = s[i++];
            }
            if(s[i] == ' ' && l < k-1)
            {
                s[j++] = s[i];
            } 
        i++;
        l++;
    }
        s[j] = '\0';
    return s;
    
}
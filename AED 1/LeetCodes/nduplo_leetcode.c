bool checkIfExist(int* arr, int arrSize) 
{
    int ver = 0;
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            if(i != j && (2*arr[j] == arr[i] || 2*arr[i] == arr[j]))
            {
             return true;
            }
        }
        
    }
    return false;
    
}
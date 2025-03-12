
int** generate(int numRows, int* returnSize, int** returnColumnSizes) 
{   
    *returnSize = numRows;
    *returnColumnSizes = (int*) malloc(numRows * sizeof(int));
    int **pascal = (int**) malloc(numRows * sizeof(int*));

    for(int i = 0; i < numRows; i++)
    {
        pascal[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        for(int j = 0; j <= i; j++)
        {
       if (j == 0 || j == i) {
            pascal[i][j] = 1;
        }
        else{
        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
        }
    
}
      return pascal;
}

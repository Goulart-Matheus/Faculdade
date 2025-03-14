/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

           int i, j;

           for (i = 0; i < numsSize; i++){

               for (j = 1; j < numsSize; j++){  

               if (nums [i] + nums [j] == target)

                   {
                       int* indices = malloc(sizeof(int) * 2);

                       indices [0] = i;
                       indices [1] = j;

                       *returnSize = 2;
                       return indices;
                   }
               }
           }
           return 0;
       }


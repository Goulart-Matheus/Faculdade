void moveZeroes(int* nums, int numsSize) {
   int ponteiro = 0;

   for(int i = 0; i < numsSize; i++){
     if(nums[i] != 0)
     {
        nums[ponteiro] = nums[i];
        ponteiro++;
     }

   }
        while(ponteiro < numsSize){
        nums[ponteiro] = 0;
        ponteiro++;
}
}
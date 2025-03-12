int dominantIndex(int* nums, int numsSize) {
    float maior = 0;
    int l = 0;
    for(int i = 0; i<numsSize; i++){
        if(maior < nums[i]){
            maior = nums[i];
            l = i;
        }
    }
    for(int j=0; j<numsSize; j++){
        if(maior/2 < nums[j] && j != l)
        {
            return -1;
        }
    
    }
    return l;
}
/*最大子列和问题,在线处理*/
int* max_sum_subarray(int length, int array[]){  
    int thisSum = 0, maxSum = 0;  
    int first_temp = 0, first = 0, last = 0, N = 0;  
    int all_negetive = 0;  
    int* res = new int[3];  
    for(int i = 0; i < length; i++){  
        thisSum += array[i];  
        N += 1;  
        if(thisSum > maxSum){  
            maxSum = thisSum;  
            last = array[i];  
            first_temp = array[i - N + 1];  
        }  
        else if(thisSum < 0){  
            thisSum = 0;  
            N = 0;  
        }  
        first = first_temp;  
        if(array[i] < 0){  
            all_negetive += 1;  
        }  
    }  
    res[0] = maxSum;  
    res[1] = first;  
    res[2] = last;  
    if(all_negetive == length){  
        res[1] = array[0];  
        res[2] = array[length - 1];  
    }  
    return res;  
}  

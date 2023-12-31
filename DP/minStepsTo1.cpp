// brute force

int countStepsTo1(int n){

    if(n==1) return 0;
    int a=INT_MAX,b=a,c=b;
    
     a = countStepsTo1(n-1);
    
    if(n%2==0)
        b=countStepsTo1(n/2);
    if(n%3==0)
        c=countStepsTo1(n/3);
    
    return  1+min(a,min(b,c));
        
}

//using dynamic programming
#include <cmath>
int countStepsTo1(int n){
	
    int a[n+1];
     
    a[1]=0; a[2]=a[3]=1;
   int b,c;
    for(int i=4 ;i<n+1;i++)
    {   
        b=c=n;
     
       if(i%2==0) b=a[i/2];
        if(i%3==0) c=a[i/3];
     
      a[i]=1+ min(a[i-1] ,min(b,c));
    }
return a[n];
}





//memorization using recursion
/*
#include<bits/stdc++.h>
int countstepsto1(int n ,int *arr)
{
    if(n==1)
    {
        arr[n]=0;
        return arr[n];
    }
      int a=INT_MAX,b=a,c=b;
 
    if(arr[n]!=-1)
        return 1+arr[n];
     a = countstepsto1(n-1,arr);
    
    if(n%2==0)
        b=countstepsto1(n/2,arr);
    if(n%3==0)
        c=countstepsto1(n/3,arr);
    
    
    arr[n] = min(a,min(b,c));
    
    return  1+arr[n];
}

int countStepsTo1(int n){

   if(n==1) return 0;
    
    int *ans= new int[n+1];
    for(int i=0 ;i<n+1 ;i++)
        ans[i]=-1;
    
    return countstepsto1(n,ans);

}*/
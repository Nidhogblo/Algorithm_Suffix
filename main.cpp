#include <iostream>
#include <algorithm>
#include<cstring>
#include "suffix.cpp"
using namespace std;
int  compare(string s0, string s1, int n);
bool sffx_comp(suffix s0, suffix s1) ;
void search_array(string s, string pattern, int sa[], int array[], int *indx);
void fill_array(string s, int arr[]);


void search_array(string s, string pattern, int sa[], int array[], int *indx) {
   int patLen,strLen,l,r;
   patLen = pattern.size();
   strLen = s.size();
   l = 0, r = strLen - 1;   
   while(l <= r) {
      int m = l + (r - l)/2;
      string tempStr = s.substr(sa[m]);
      int res = compare(pattern,tempStr, patLen);
      if(res == 0) {   
        (*indx)++;
        array[(*indx)] = sa[m];
      }
      if(res < 0){r = m -1;}
      else{l = m +1;}
   }
}
int compare(string s0, string s1, int n) {
   int i = 0;
   while(n--) {
      if(s0[i] != s1[i]){return s0[i] - s1[i];}
      i++;
   }
   return 0;
}
void fill_array(string s, int arr[]) {
   int n;;
   n = s.size();
   suffix all[n];   
   for(int i = 0; i<n; i++) {
      all[i].index = i;
      all[i].suff = s.substr(i);    
   }
   sort(all, all+n, sffx_comp);
   for(int i = 0; i<n; i++){arr[i] = all[i].index;}
}
bool sffx_comp(suffix s0, suffix s1) {     
   if(s0.suff<s1.suff)
      return true;
   return false;
}


int main() {
   string str = "Resultado amistoso";
   string search = "ist";
   int la[str.size()];
   int arr[str.size()];
   int indx = -1;

   fill_array(str,  arr);
   search_array(str, search, arr, la, &indx);
   for(int i = 0; i <= indx; i++) {
      cout << "position: " << la[i]<<endl;
   }
}
**esaxx** is a C++ template library supporting to build an enhanced suffix array  which is useful for various string algorithms.
For an input text of length N, esaxx builds a suffix tree in linear time using almost 20N bytes working space (alphabet size independent).

In construction, esaxx first build a suffix array, and then compute the inversed suffix array, and finally obtain the height array. By using a height array, internal nodes in a suffix tree are enumerated in post-order.

It also provides the sample program to enumerate the statistics of all substrings appeared in a text in linear time.

For a suffix array construction, I use sais.hxx, the induced sorting algorithm implemented by Yuta Mori.

## How to use ##

  1. Copy esa.hxx and sais.hxx to your src directory.
  1. include "esa.hxx"
  1. call esaxx();

## Sample code ##

Eumerating all substrings corresponding to internal nodes.
```

   #include "esa.hxx"

   vector<char> T;         // input text
   readFile(file_name, T); // read file into T
   int n = T.size();

   vector<int>  SA(n);     // suffix array
   vector<int>  L (n);     // left boundaries of internal node
   vector<int>  R (n);     // right boundaries of internal node 
   vector<int>  D (n);     // depths of internal node

   int alphaSize = 0x100;  // This can be very large
   int nodeNum = 0;
   if (esaxx(T.begin(), SA.begin(),
            L.begin(), R.begin(),  D.begin(),
            n, alphaSize, nodeNum) == -1){
       return -1;
   }

   // An internal node is represented by a triple (L[i], R[i], D[i]) .
   // The node coressponds to SA[L[i]...R[i]-1], and the depth is D[i]

   for (int i = 0; i < nodeNum; ++i){
      // the frequency of substrings corresponding to the internal node
      //   and the depth of the internal node
      cout << R[i] - L[i] << "\t"  << D[i] << "\t"; 
      int beg = SA[L[i]];
      int len = D[i];
      for (int j = 0; j < len; ++j){
          cout << T[beg + j];
      }
      cout << endl;
   }

```

#include <gtest/gtest.h>
#include <vector>
#include "esa.hxx"

using namespace std;

namespace esa_test{

class ESATester{
public:
  ESATester(const vector<int>& T,
            int alphaNum): T_(T){
    SA_.resize(T.size());
    L_.resize(T.size());
    R_.resize(T.size());
    D_.resize(T.size());
    if(esaxx(T.begin(), SA_.begin(),
             L_.begin(), R_.begin(), D_.begin(),
             (int)T.size(), alphaNum_, nodeNum_) == -1){
      throw("Failed to create esa");
    }
    L_.resize(nodeNum_);
    R_.resize(nodeNum_);
    D_.resize(nodeNum_);
  }
  void check(int nodeNum,
             const vector<int>& SA,
             const vector<int>& L,
             const vector<int>& R,
             const vector<int>& D){
    ASSERT_EQ(nodeNum, nodeNum_);
    ASSERT_EQ(SA, SA_);
    ASSERT_EQ(L, L_);
    ASSERT_EQ(R, R_);
    ASSERT_EQ(D, D_);
  }
private:
  int alphaNum_;
  int nodeNum_;
  vector<int> T_;
  vector<int> SA_;
  vector<int> L_;
  vector<int> R_;
  vector<int> D_;
};

TEST(esa, small){
  vector<int> T;
  T.push_back('b');
  T.push_back('b');
  T.push_back('a');
  ESATester esa_t(T, 0x100);
  int nodeNum = 2;
  int SAExpect[3] = {2, 1, 0};
  int LExpect[2] = {1, 0};
  int RExpect[2] = {3, 3};
  int DExpect[2] = {1, 0};
  esa_t.check(nodeNum,
              vector<int>(SAExpect, SAExpect+3),
              vector<int>(LExpect, LExpect+2),
              vector<int>(RExpect, RExpect+2),
              vector<int>(DExpect, DExpect+2));
}

TEST(esa, two_alpha){
  vector<int> T;
  T.push_back('b');
  T.push_back('a');
  ESATester esa_t(T, 0x100);
  int nodeNum = 1;
  int SAExpect[2] = {1, 0};
  int LExpect[1] = {0};
  int RExpect[1] = {2};
  int DExpect[1] = {0};
  esa_t.check(nodeNum,
              vector<int>(SAExpect, SAExpect+2),
              vector<int>(LExpect, LExpect+1),
              vector<int>(RExpect, RExpect+1),
              vector<int>(DExpect, DExpect+1));
}

TEST(esa, one_alpha){
  vector<int> T;
  for(size_t i = 0; i < 2; ++i){
    T.push_back('a');    
  }
  ESATester esa_t(T, 0x100);
  int nodeNum = 2;
  int SAExpect[2] = {1, 0};
  int LExpect[2] = {0, 0};
  int RExpect[2] = {2, 2};
  int DExpect[2] = {1, 0};
  esa_t.check(nodeNum,
              vector<int>(SAExpect, SAExpect+2),
              vector<int>(LExpect, LExpect+2),
              vector<int>(RExpect, RExpect+2),
              vector<int>(DExpect, DExpect+2)); 
}

TEST(esa, one_char){
  vector<int> T;
  T.push_back('a');    
  ESATester esa_t(T, 0x100);
  int nodeNum = 1;
  int SAExpect[1] = {0};
  int LExpect[1] = {0};
  int RExpect[1] = {1};
  int DExpect[1] = {0};
  esa_t.check(nodeNum,
              vector<int>(SAExpect, SAExpect+1),
              vector<int>(LExpect, LExpect+1),
              vector<int>(RExpect, RExpect+1),
              vector<int>(DExpect, DExpect+1)); 
}

}// esa_test

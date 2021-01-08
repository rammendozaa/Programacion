#include<iostream>
#include<vector>

using namespace std;

void fill(vector<int> &v, int size)
{
  int num=0;
  for(int i=0; i<size ; i++)
  {
    cin>>num;
    v.push_back(num);
    //cout <<v[i]<< '\n';
  }
}

int checkCriteria(vector<int> v, int size, int k)
{
  int criteria=0, j=0;

  for(int i=0 ; i<size ; i++)
  {
    for(j=(i+1) ; j<size ; j++ )
    {
      if(v[i]!=v[j])
      {
        if(((v[i]+v[j])%k)==0)
        {
          criteria++;
        }
      }

    }
  }

  return criteria;
}
int main(int argc, char const *argv[])
{
  vector<int> numbers;
  int n=0, k=0, res;

  cin>>n;
  cin>>k;
  fill(numbers,n);
  res=checkCriteria(numbers,n,k);
  cout<<res;
  return 0;
}

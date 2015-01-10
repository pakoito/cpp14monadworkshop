#include <boost/optional.hpp>
#include <iostream>
#include <cmath>

template<typename T>
std::ostream& operator<<(std::ostream& os,const boost::optional<T>& x)
{
  if(x)return os<<x.get();
  else return os<<"none";
}

using namespace boost;

optional<double> inv(double x)
{
  if(x==0.0)return none;
  else      return 1.0/x;
}

optional<double> sqr(double x)
{
  if(x<0.0)return none;
  else     return std::sqrt(x);
}

optional<double> arcsin(double x)
{
  if(x<-1.0||x>1.0)return none;
  else             return std::asin(x);
}

template<typename F>
optional<double> call(const optional<double>& x, F f)
{
  return x?f(x.get()):none;
}

optional<double> ias(double x)
{
  return call(call(sqr(x),arcsin),inv);
}

int main()
{
  std::cout<<"ias(1.0)="<<ias(1.0)<<"\n";
  std::cout<<"ias(-1.0)="<<ias(-1.0)<<"\n";
  std::cout<<"ias(2.0)="<<ias(-1.0)<<"\n";
  std::cout<<"ias(0.0)="<<ias(-1.0)<<"\n";
}
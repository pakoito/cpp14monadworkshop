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

optional<int> inv(double x)
{
  if(x==0.0)return none;
  else      return int(1.0/x);
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

template<typename T,typename F>
auto call(const optional<T>& x, F f)
{
  return x?f(x.get()):none;
}

auto ias(double x)
{
  return call(call(sqr(x),arcsin),inv);
}

int main()
{
  std::cout<<"ias(1.0)="<<ias(1.0)<<"\n";
  std::cout<<"ias(-1.0)="<<ias(-1.0)<<"\n";
  std::cout<<"ias(2.0)="<<ias(2.0)<<"\n";
  std::cout<<"ias(0.0)="<<ias(0.0)<<"\n";
}

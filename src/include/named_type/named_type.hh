#pragma once

namespace util
{

template <typename T, typename Parameter,
          template <typename> class... Skills>
class named_type :
  public Skills<named_type<T, Parameter, Skills...>>...
{
public:
  explicit named_type(const T& value);

  T& get();
  const T& get() const;

private:
  T value_;
};

#include "named_type_v3.hh"

}  // namespace util

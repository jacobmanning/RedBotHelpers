template <typename T, typename Parameter,
          template <typename> class... Skills>
named_type<T, Parameter, Skills...>::named_type(const T& value) :
  value_{value} {}

template <typename T, typename Parameter,
          template <typename> class... Skills>
T& named_type<T, Parameter, Skills...>::get()
{
  return value_;
}

template <typename T, typename Parameter,
          template <typename> class... Skills>
const T& named_type<T, Parameter, Skills...>::get() const
{
  return value_;
}

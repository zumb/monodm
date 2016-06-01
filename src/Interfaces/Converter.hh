<?hh //strict
namespace Zumb\Storage\Interfaces;

interface Converter<Ti, To>
{
  public function in(Ti $value):To;

  public function out(To $value, classname<Ti> $class):Ti;
}

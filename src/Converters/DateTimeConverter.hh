<?hh //strict
namespace Zumb\Storage\Converters;

use Zumb\Storage\Interfaces\Converter;

class DateTimeConverter implements Converter<\DateTime, string>
{
  public function in(\DateTime $time):string
  {
    return $time->format(\DateTime::ISO8601);
  }

  public function out(string $time, classname<\DateTime> $class):\DateTime
  {
    return \DateTime::createFromFormat(\DateTime::ISO8601, $time);
  }
}

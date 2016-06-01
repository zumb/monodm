<?hh //strict
namespace Zumb\Storage;

use Zumb\Storage\Interfaces\Converter;

class ConvertersCollection
{
  protected Map<string, Converter<mixed, mixed>> $converters = Map {};

  public function get(string $inType):?Converter<mixed, mixed>
  {
    return $this->converters->get($inType);
  }

  public function add(string $inType, Converter<mixed, mixed> $converter):void
  {
    $this->converters->set($inType, $converter);
  }

}

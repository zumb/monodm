<?hh //strict
namespace Zumb\Storage\Converters;

use Zumb\Storage\Interfaces\Storable;
use Zumb\Storage\Interfaces\Converter;
use Zumb\Storage\ConvertersCollection;
use Zumb\Storage\Reflection;

class StorableConverter implements Converter<Storable, array<string, mixed>>
{

  public function __construct(
    protected Reflection $reflection,
    protected ConvertersCollection $converters
  ) {}

  public function in(Storable $object):array<string, mixed>
  {
    $array = [];
    $class = $this->reflection->reflectionClass($object);
    foreach($class->getProperties() as $property) {
      $value = $property->getValue($object);
      $converter = $this->converters->get($property->getTypeText());
      if($converter) {
        $value = $converter->in($value);
      }
      $array[$property->getName()] = $value;
    }
    return $array;
  }

  public function out(array<string, mixed> $data, classname<Storable> $className):Storable
  {
    $class = $this->reflection->reflectionClass($className);
    $object = $class->newInstance($data);
    foreach($class->getProperties() as $property) {
      $converter = $this->converters->get($property->getTypeText());
      $value = $data[$property->getName()];
      if($converter) {
        $value = $converter->out($value, $property->getTypeText());
      }
      $property->setValue($object, $value);
    }
    return $object;
  }

}

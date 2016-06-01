<?hh //partial

namespace spec\Zumb\Storage\Converters;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;
use Zumb\Storage\Reflection;
use Zumb\Storage\Interfaces\Storable;
use Zumb\Storage\Converters\DateTimeConverter;
use Zumb\Storage\ConvertersCollection;

class StorableConverterSpec extends ObjectBehavior
{
  public function let($reflection, $property, $class, $storable, $converters)
  {
    $storable->beADoubleOf(Storable::class);
    $property->beADoubleOf(\ReflectionProperty::class);
    $reflection->beADoubleOf(Reflection::class);
    $class->beADoubleOf(\ReflectionClass::class);
    $converters->beADoubleOf(ConvertersCollection::class);
    $this->beConstructedWith($reflection, $converters);
  }

  public function it_converts_properties_without_converter_to_array(
    $reflection, $class, $property, $storable, $converters)
  {
    $reflection->reflectionClass($storable)
      ->willReturn($class);
    $class->getProperties()
      ->willReturn([$property]);
    $property->getName()
      ->willReturn("test");
    $property->getValue($storable)
      ->willReturn("value");
    $property->getTypeText()
      ->willReturn("type");
    $converters->get(Argument::any())
      ->willReturn(null);
    $this->in($storable)
      ->shouldReturn(["test" => "value"]);
  }

  public function it_converts_using_converter_to_array(
    $reflection, $class, $property, $storable, $converters)
  {
    $reflection->reflectionClass($storable)
      ->willReturn($class);
    $class->getProperties()
      ->willReturn([$property]);
    $property->getName()
      ->willReturn("test");
    $property->getValue($storable)
      ->willReturn(new \DateTime("2016-01-01T00:00:00-0800"));
    $property->getTypeText()
      ->willReturn("type");
    $converters->get(Argument::any())
      ->willReturn(new DateTimeConverter());
    $this->in($storable)
      ->shouldReturn(["test" => "2016-01-01T00:00:00-0800"]);
  }


}

<?hh //strict
namespace Zumb\Storage;

class Reflection
{
  public function reflectionClass(mixed $object):\ReflectionClass
  {
    return new \ReflectionClass($object);
  }

  public function reflectionMethod(mixed $class, string $name):\ReflectionMethod
  {
    return new \ReflectionMethod($class, $name);
  }
}

<?hh //strict
namespace Zumb\Storage;

use Zumb\Storage\Converters\StorableConverter;
use Zumb\Storage\Interfaces\Storable;

class StorableOutIterator implements Iterator<Storable>
{
  protected int $index = 0;

  public function __construct(
    protected StorableConverter $converter,
    protected array<array<string, mixed>> $collection,
    protected classname<Storable> $convertToClass
  ) {}

  public function current():Storable
  {
    return $this->converter->out(
      $this->collection[$this->index], $this->convertToClass
    );
  }

  public function next():void
  {
    $this->index++;
  }

  public function rewind():void
  {
    $this->index--;
  }

  public function valid():bool
  {
    return key_exists($this->index, $this->collection);
  }
}

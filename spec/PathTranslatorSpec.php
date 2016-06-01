<?hh //partial

namespace spec\Zumb\Storage;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

class PathTranslatorSpec extends ObjectBehavior
{

  public function it_translates_path_to_foreign_keys()
  {
    $this->getForeignKeys("/accounts/1/users/2")
      ->shouldBeLike([
        Pair{"accounts", "1"}
      ]);
  }

  public function it_ignores_one_level()
  {
    $this->getForeignKeys("/accounts")
      ->shouldReturn([]);
  }

}

<?hh //strict
namespace Zumb\Storage;

class PathTranslator
{
  const REGEXP = '/\\/([^\\/]+)(?:\\/([^\\/]+))?/';

  public function getForeignKeys(string $path):array<Pair<string, string>>
  {
    $keys = [];
    $segments = [];
    preg_match_all(self::REGEXP, $path, $segments, PREG_SET_ORDER);
    array_pop($segments);
    foreach($segments as $segment) {
      $keys[] = Pair{$segment[1], $segment[2]};
    }
    return $keys;
  }

}

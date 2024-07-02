#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
namespace Joe {
  class KeyboardEvent{

    public:
      static void Update(SDL_Event event);
      static bool IsKeyPressed(Sint32 key);
  };
}

#include <memory>
#include <vector>

namespace peekie::core {
    template <typename InputEvent, typename Subscriber>
    class BaseInputEventHandler {
        std::vector<std::shared_ptr<Subscriber>> subscribers;

        std::shared_ptr<InputEvent> last_event;

    public:
        void register_subscriber(std::shared_ptr<Subscriber> subscriber) {
            subscribers.push_back(subscriber);
        }
    };
}
//Name: Tanim Islam

// Invariants of the sequence class:

// 1. The number of items in the sequence is stored in the member variable
// used.
// 2. For an empty sequence, we do not care what is stored in any of data; for
// a non-empty sequence, the items are stored in their sequence order from
// data[0] to data[used-1], and we don’t care what is stored in the rest of
// data.
// 3. If there is a current item, then it lies in data[current_index]; if there is
// no current item, then current_index equals used

#include "sequence1.h"

#include <cassert>

using namespace std;

namespace main_savitch_3 {

  // Constructor: 

  sequence::sequence() {
    // Postcondition: The sequence has been initialized as an empty sequence.

    used = 0;
    current_index = 0;

  }

  // Modification Member Functions: 

  void sequence::start() {
    // Postcondition: The first item on the sequence becomes the current item
    // (but if the sequence is empty, then there is no current item).
    current_index = 0;
  }

  void sequence::advance() {
    // Precondition: is_item returns true.
    // Postcondition: If the current item was already the last item in the
    // sequence, then there is no longer any current item. Otherwise, the new
    // current item is the item immediately after the original current item.

    assert(is_item());

    ++current_index;
  }

  void sequence::insert(const value_type & entry) {
    // Precondition: size( ) < CAPACITY.
    // Postcondition: A new copy of entry has been inserted in the sequence 
    // before the current item. If there was no current item, then the new entry 
    // has been inserted at the front. In either case, the new item is now the
    // current item of the sequence.

    assert(size() < CAPACITY);

    size_t i;

    if (!is_item())
      // When there is no valid item at the current index or when the current index is not less than used, 
      // then current_index is intialized as the first entry of the array.
      current_index = 0;

    for (i = used; i > current_index; --i) {
      // You are essentially shifting all elements of the array to the right, until you reach the current index. 
      // That is where you insert your new entry. 
      data[i] = data[i - 1];

    }

    // After all of the elements have been shifted to the right, you insert at the current index and increment used by 1. 
    data[current_index] = entry;
    ++used;

  }

  void sequence::attach(const value_type & entry) {
    // Precondition: size( ) < CAPACITY.
    // Postcon dition: A new copy of entry has been inserted in the sequence after
    // the current item. If there was no current item, then the new entry has 
    // been attached to the end of the sequence. In either case, the newly
    // inserted item is now the current item of the sequence.

    size_type i;

    assert(size() < CAPACITY);

    if (!is_item()) {
      // Remember for is_item() to return true, current_index < used.  
      // When there isn't a valid item at current index and you want to attach
      // an element at either the beginning of the sequence or at the end (Boundary cases). 
      // If we want to attach an item in an empty sequence (current_index = used = 0) which means is_item() will not be true.
      // A successful function call automatically indiciates that a valid 
      // entry has been taken as a parameter, so we can incrememnt used by 1, and store the entry at "used-1". 
      // When trying to attach at the end of a sequence such that current index = used and therefore not a valid item either
      // We do the same procedure of incrememting used by 1 and then store the entry at "used-1". 

      ++used;
      current_index = used - 1; //Current index must always be less than used. 
      data[current_index] = entry;
      return;

    }

    for (i = used; i > current_index + 1; --i) {

      data[i] = data[i - 1];

    }

    ++used;
    data[++current_index] = entry;

  }

  void sequence::remove_current() {
    // Precondition: is_item returns true. Meaning there is a valid item to remove at the current index.
    // Postcondition: The current item has been removed from the sequence, and the
    // item after this (if there is one) is now the new current item.

    assert(is_item());

    size_t i;

    for (i = current_index + 1; i < used; ++i) {

      data[i - 1] = data[i];
    }

    --used;

  }

  // Constant Member Functions:

  sequence::size_type sequence::size() const {
    // Postcondition: The return value is the number of items in the sequence

    return used;
  }

  bool sequence::is_item() const {
    // Postcondition: A true return value indicates that there is a valid
    // "current" item that may be retrieved by activating the current
    // member function (listed below). A false return value indicates that
    // there is no valid current item. So, the current_index has to be less than "used".

    return (current_index < used);
  }

  sequence::value_type sequence::current() const {
    // Precondition: is_item( ) returns true.
    // Postcondition: The item returned is the current item in the sequence.

    assert(is_item());

    return data[current_index];
  }

}
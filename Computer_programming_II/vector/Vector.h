// Vector class definition.
#ifndef VECTOR_H
#define VECTOR_H
using namespace std;

class Vector 
{
public:
   Vector( unsigned int n = 0, const int val = 0 ); // Constructs a container with n elements. Each element is a copy of val.
   Vector( int *first, int *last ); // Constructs a container with as many elements as the range [first,last),
                                    // with each element emplace-constructed from its corresponding element in that range,
                                    // in the same order.
   Vector( const Vector &vectorToCopy ); // Constructs a container with a copy of each of the elements in vectorToCopy, in the same order.
   ~Vector(); // Destroys the container object.

   int* begin(); // Returns a pointer pointing to the first element in the vector.
                 // If the container is empty, the returned pointer shall not be dereferenced.
   int* end(); // Returns an pointer referring to the past-the-end element in the vector container.
               // The past-the-end element is the theoretical element that would follow the last element in the vector.
               // It does not point to any element, and thus shall not be dereferenced.
               // If the container is empty, the returned pointer shall not be dereferenced. 
   unsigned int getSize() const; // Returns the number of elements in the vector.
   void resize( unsigned int n ); // Resizes the container so that it contains n elements.
                                  // If n is smaller than the current container size,
                                  // the content is reduced to its first n elements, removing those beyond.
                                  // If n is greater than the current container size,
                                  // the content is expanded by inserting at the end as many elements as needed to reach a size of n.
                                  // The new elements are initialized as 0.
                                  // If n is also greater than the current container capacity,
                                  // an automatic reallocation of the allocated storage space takes place.
   void resize( unsigned int n, const int val ); // The new elements are initialized as copies of val.
   unsigned int getCapacity() const; // Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
   bool empty() const; // Returns whether the vector is empty (i.e. whether its size is 0).
   void reserve( unsigned int n ); // Requests that the vector capacity be enough to contain n elements.
                                   // If n is greater than the current vector capacity,
                                   // the function causes the container to reallocate its storage increasing its capacity to n.
                                   // In all other cases, the function call does not cause a reallocation and
                                   // the vector capacity is not affected.
   void shrink_to_fit(); // Requests the container to reduce its capacity to fit its size.

//   int& at( unsigned int n );
   int& front(); // Returns a reference to the first element in the vector.
                 // Calling this function on an empty container causes undefined behavior.
   int& back(); // Returns a reference to the last element in the vector.
                // Calling this function on an empty container causes undefined behavior. 

   void assign( int n, const int val ); // Assigns new contents to the vector, replacing its current contents,
                                        // and modifying its size accordingly.
                                        // The new contents are n elements, each initialized to a copy of val.
   void assign ( int *first, int *last ); // Assigns new contents to the vector, replacing its current contents,
                                          // and modifying its size accordingly.
                                          // The new contents are elements constructed from each of the elements
                                          // in the range between first and last, in the same order.
   void push_back( const int val ); // Adds a new element at the end of the vector, after its current last element.
                                    // The content of val is copied to the new element.
                                    // This effectively increases the container size by one,
                                    // which causes an automatic reallocation of the allocated storage space
                                    // if -and only if- the new vector size surpasses the current vector capacity.
   void pop_back(); // Removes the last element in the vector, effectively reducing the container size by one.
   int* insert( int *position, const int val ); // The vector is extended by inserting a new element before the element at the specified position,
                                                // effectively increasing the container size by one.
                                                // This causes an automatic reallocation of the allocated storage space if -and only if-
                                                // the new vector size surpasses the current vector capacity.
                                                // Relocates all the elements that were after position to their new positions.
   int* insert( int *position, unsigned int n, const int val ); // The vector is extended by inserting n new elements before the element at the specified position,
                                                                // effectively increasing the container size by the number of elements inserted.
                                                                // This causes an automatic reallocation of the allocated storage space if -and only if-
                                                                // the new vector size surpasses the current vector capacity.
                                                                // Relocates all the elements that were after position to their new positions.
   int* insert( int *position, int *first, int *last ); // The vector is extended by inserting new elements before the element at the specified position,
                                                        // effectively increasing the container size by the number of elements inserted.
                                                        // This causes an automatic reallocation of the allocated storage space if -and only if-
                                                        // the new vector size surpasses the current vector capacity.
                                                        // Relocates all the elements that were after position to their new positions.
   int* erase( int *position ); // Removes from the vector a single element.
                                // This effectively reduces the container size by one.
                                // Relocates all the elements after the element erased to their new positions.
   int* erase( int *first, int *last ); // Removes from the vector the range [first,last) of elements.
                                        // This effectively reduces the container size by the number of elements removed.
                                        // Relocates all the elements after the segment erased to their new positions.
   void swap( Vector &x ); // Exchanges the content of the container by the content of x, which is another vector. Sizes may differ.
   void clear(); // Removes all elements from the vector, leaving the container with a size of 0.
                 // The vector capacity does not change, and no reallocations happen due to calling this function.
   void display(); // Displays all elements in the vector.

//   const Vector &operator=( const Vector &right );
private:
   unsigned int size; // the number of elements in the vector
                      // // This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
   unsigned int capacity; // the size of the storage space currently allocated for the vector, expressed in terms of elements.
                          // This capacity is not necessarily equal to the vector size. It can be equal or greater,
                          // with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
   int *ptr; // points to a dynamically allocated array which is used to store the elements of the vector
}; // end class Vector

#endif
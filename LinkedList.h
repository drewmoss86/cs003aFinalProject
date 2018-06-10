/***************************************************************************
 * AUTHOR          : Andrew Moss
 * Final Project   : GUI Linked Lists
 * CLASS           : CS 003 A
 * SECTION         : MW: 1:00 - 2:25 pm
 *                   TR: 1:00 - 3:05 pm
 * Due Date        : 06/11/18
 **************************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#endif // LINKEDLIST_H

#include <iostream>

using namespace std;

class ListEmpty
{
private:
    string message;

public:

    /**********************************************************
    *
    *  Method ListEmpty(): Class ListEmpty
    *  _________________________________________________________
    *  This constructor initializes message to "List is empty"
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function initializes message to "List is empty"
    ***********************************************************/
    ListEmpty()
    {
        message = "List is empty. ";
    }

    /**********************************************************
    *
    *  Method ListEmpty(): Class ListEmpty
    *  _________________________________________________________
    *  This constructor initializes message to a messaged passed in
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  msg : message to output if list is emptys
    *
    *  POST-CONDITIONS
    *  This function initializes message to msg passed in
    ***********************************************************/
    ListEmpty( string msg )
    {
        message = msg;
    }

    /**********************************************************
    *
    *  Method what(): Class ListEmpty
    *  _________________________________________________________
    *  This method returns a string with a message for an empty list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function returns a string with a message for an empty list
    ***********************************************************/
    string what()
    {
        return message;
    }
};

template <typename E>
struct Node
{
    E data;
    Node<E> *next;
    Node( E data ) : data(data), next(0) {}

};

template <typename E>
class Iterator
{
private:
    Node<E> *current;

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    //Initialize the iterator.  Basically just need to set the pointer to NULL
    Iterator()
    {
        current = NULL;
    }

    //Initialize the iterator with parameter passed int.
    //Need to set the pointer equal to whatever pointer is passed in.
    Iterator( Node<E> *ptr )
    {
        current = ptr;
    }

    /**************
    ** ACCESSORS **
    **************/
    //This function overloads the dereferencing operator*.
    //It should return the info contained in the node.
    E operator*()
    {
        return current->data;
    }

    //This function overloads the pre-increment operator++.
    //It should return an iterator that is pointing to the next node.
    Iterator<E> operator++()
    {
        current = current->next;
        return *this;
    }

    //This function overloads the equality operator.
    //Should return true if this iterator is equal to the iterator
    //specified by right, otherwise it returns false.
    bool operator==( const Iterator<E>& rhs ) const
    {
        if(current == rhs.current)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    //This function overloads the not equal to operator.
    //Should return true if this iterator is not equal to the iterator
    //specified by right, otherwise it returns false.
    bool operator!=( const Iterator<E>& rhs ) const
    {
        if(current != rhs.current)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};

template <typename E>
class LinkedList
{
private:
    Node<E> *head;  //head pointer
    Node<E> *tail;  //tail pointer

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    /**********************************************************
    *
    *  Method LinkedList(): Class LinkedList
    *  _________________________________________________________
    *  This constructor initializes the head and tail of a linked list
    *
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function initializes the head and tail of a linked list.
    *  There is no return value.
    ***********************************************************/
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    /**********************************************************
    *
    *  Method LinkedList(): Class LinkedList
    *  _________________________________________________________
    *  This constructor initializes a new list with the contents
    *    of an existing list.
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  list : new list of integers
    *
    *  POST-CONDITIONS
    *  This function initializes initializes a new list with the contents
    *    of an existing list.
    ***********************************************************/
    LinkedList( const LinkedList<E>& source )
    {
        //initialize list to be copied from source list
        head = new Node<E>(source.head->data);
        //current pointer to traverse source list
        Node<E> *source_current = source.head->next;
        //point tail to head
        tail = head;

        //if source head is empty, do nothing
        if(source.head == NULL)
        {
            return;
        }

        else
        {
            //traverse list to be copied
            while(source_current != NULL)
            {
                //create new node to be added to list
                tail->next = new Node<E>(source_current->data);
                //traverse new list
                tail = tail->next;
                //traverse source list
                source_current = source_current->next;
            }
        }

    }
    /**********************************************************
    *
    *  Method LinkedList(): Class LinkedList
    *  _________________________________________________________
    *  This destructor deallocates all remaining IntNodes
    *
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function should deallocate all remaining dynamically allocated
    *    memory (all remaining IntNodes).
    ***********************************************************/
    ~LinkedList()
    {
        Node<E> *remove_ptr = NULL;  //pointer to point to node to be removed

        //if empty, do nothing
        if(isEmpty())
        {
            return;
        }

        else
        {
            //traverse list to be deleted
            while(head != NULL)
            {
                //point to head node to be deleted
                remove_ptr = head;
                //traverse head pointer to next node in list
                head = head->next;
                //delete node that the remove pointer is pointing to
                delete remove_ptr;
            }

            //point tail to head when head reaches null
            tail = head;
        }


    }

    /**********************************************************
    *
    *  Method operator=(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    LinkedList<E> & operator=( const LinkedList<E>& source )
    {
        Node<E> *source_current = NULL;

        //check if list has already been assigned
        if(this != &source)
        {
            //if source head is empty, set copy list to empty
            if(source.head == NULL)
            {
                head = NULL;
                tail = NULL;

            }

            else
            {
                //initialize list to be copied from source list
                head = new Node<E>(source.head->data);

                //point tail to head
                tail = head;
                //current pointer to traverse source list
                source_current = source.head;
                //traverse to next source node
                source_current = source_current->next;

                //traverse list to be copied
                while(source_current != NULL)
                {
                    //create new node to be added to list
                    tail->next = new Node<E>(source_current->data);
                    //traverse new list
                    tail = tail->next;
                    //traverse source list
                    source_current = source_current->next;
                }

            }

        }

        //return new list
        return *this;

    }

    /**************
    ** ACCESSORS **
    **************/
    /**********************************************************
    *
    *  Method display(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    void display() const
    {
        if(isEmpty())
        {
            return;
        }

        else
        {
            for(Node<E> *current = head; current != NULL; current = current->next)
            {
                cout << current->data;
                if(current->next != NULL)
                {
                    cout << " ";
                }
            }

        }
    }

    /**********************************************************
    *
    *  Method display(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    bool isEmpty() const
    {
        if(head == NULL)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    /**********************************************************
    *
    *  Method length(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    int length() const
    {
        return countNodes(head);

    }

    /**********************************************************
    *
    *  Method sum(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    E sum() const
    {
        return addNodes(head);
    }

    /**********************************************************
    *
    *  Method display(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    Iterator<E> begin()
    {
        return Iterator<E>(head);
    }

    /**********************************************************
    *
    *  Method display(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    Iterator<E> end()
    {
        return Iterator<E>(NULL);
    }

    /**********************************************************
    *
    *  Method front(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    const E& front() const throw(ListEmpty)
    {
        try
        {
            if( !isEmpty() )
            {
                return head->data;

            }

            else
            {
                throw ListEmpty("List Empty: Nothing up front");

            }

        }

        catch( ListEmpty emp )
        {
            cout << emp.what() << endl;
        }

    }

    /**********************************************************
    *
    *  Method back(): Class LinkedList
    *  _________________________________________________________
    *  This method prints values stored in node of linked list
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function displays to a single line all of the int values stored
    *    in the list, each separated by a space. It should NOT output a newline
    *    or space at the end.
    ***********************************************************/
    const E& back() const throw(ListEmpty)
    {
        try
        {
            if( !isEmpty() )
            {
                return tail->data;

            }

            else
                throw ListEmpty("List Empty: Nothing in the back");

        }

        catch( ListEmpty emp )
        {
            cout << emp.what() << endl;
        }
    }


    /*************
    ** MUTATORS **
    *************/
    /**********************************************************
    *
    *  Method push_front(): Class LinkedList
    *  _________________________________________________________
    *  This method inserts a data value (within a new node) at
    *    the front end of the list.
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  value : integer value to be stored in node
    *
    *  POST-CONDITIONS
    *  This function inserts a data value (within a new node) at
    *    the front end of the list.
    ***********************************************************/
    void push_front( const E& value )
    {
        //check if list is empty
        if(isEmpty())
        {
            //point head to new node
            head = new Node<E>(value);
            //point tail to head
            tail = head;
        }

        //if not empty
        else
        {
            //new node to be added to front of list
            Node<E> *newNode = new Node<E>(value);
            //point new node's next to head
            newNode->next = head;
            //head points to new node
            head = newNode;
        }


    }

    /**********************************************************
    *
    *  Method push_back(): Class LinkedList
    *  _________________________________________________________
    *  This method inserts a data value (within a new node) at
    *    the back end of the list.
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  value : integer value to be stored in node
    *
    *  POST-CONDITIONS
    *  This function inserts a data value (within a new node) at
    *    the back end of the list.
    ***********************************************************/
    void push_back( const E& value )
    {
        Node<E> *newNode = new Node<E>(value);

        //check if list is empty
        if(isEmpty())
        {
            //initialize list with new node
            head = newNode;
            //point tail to head
            tail = newNode;
        }

        //if not empty
        else
        {
            //create next node after tail
            tail->next = newNode;
            //traverse tail to the new node
            tail = tail->next;
        }
    }

    /**********************************************************
    *
    *  Method pop_front(): Class LinkedList
    *  _________________________________________________________
    *  This method removes the value (actually removes the node
    *    that contains the value) at the front end of the list.
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function removes the value (actually removes the node
    *    that contains the value) at the front end of the list.
    *    Do nothing if the list is already empty. In other words,
    *    do not call the exit function in this function as we did
    *    with the IntVector's pop_front.
    ***********************************************************/
    void pop_front() throw(ListEmpty)
    {
        try
        {
            if( !isEmpty() )
            {
                //pointer to point to node to be removed
                Node<E> *remove_ptr = NULL;
                //point to whatever is at the front of list
                remove_ptr = head;
                //point head to next node
                head = head->next;
                //delete whatever it's being pointed to
                delete remove_ptr;
            }

            else
                throw ListEmpty("List empty: Cannot pop_front");
        }

        catch( ListEmpty emp )
        {
            cout << emp.what() << endl;
        }
    }

    /**********************************************************
    *
    *  Method clear(): Class LinkedList
    *  _________________________________________________________
    *  This method removes the value (actually removes the node
    *    that contains the value) at the front end of the list.
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function removes the value (actually removes the node
    *    that contains the value) at the front end of the list.
    *    Do nothing if the list is already empty. In other words,
    *    do not call the exit function in this function as we did
    *    with the IntVector's pop_front.
    ***********************************************************/
    void clear()
    {
        if(isEmpty())
        {
            return;
        }

        else
        {
            while(head != NULL)
            {
                pop_front();
            }
            tail = NULL;
        }
    }

    /**********************************************************
    *
    *  Method select_sort(): Class LinkedList
    *  _________________________________________________________
    *  This method sorts the list into ascending order using the
    *    selection sort algorithm
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function sorts the list into ascending order using the
    *    selection sort algorithm
    ***********************************************************/
    void select_sort()
    {
        //if list is empty, do nothing
        if(isEmpty())
        {
            return;
        }
        //pointer set to point at min value
        Node<E> *min = NULL;
        //variable to hold value for swap
        E value;

        //traverse linked list
        for(Node<E> *i = head; i != NULL; i = i->next)
        {
            //set min pointer to i pointer
            min = i;
            //traverse subsequent nodes to compare with i
            for(tail = i->next; tail != NULL; tail = tail->next)
            {
                //if the data value is less than the min
                if(tail->data < min->data)
                {
                    //reset min pointer to the tail
                    min = tail;
                }
            }

            //hold larger value for swap
            value = i->data;
            //move smaller value ahead
            i->data = min->data;
            //move larger value after
            min->data = value;
        }
    }

    /**********************************************************
    *
    *  Method insert_sorted(): Class LinkedList
    *  _________________________________________________________
    *  This method assumes the values in the list are in sorted
    *    (ascending) order and inserts the data into the appropriate
    *    position in the list (so that the values will still be in
    *    ascending order after insertion).
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  value : integer value to be stored in node
    *
    *  POST-CONDITIONS
    *  This function sorts the list into ascending order using the
    *    selection sort algorithm
    ***********************************************************/
    void insert_sorted( const E& value )
    {
        Node<E> *newNode = new Node<E>(value);

        //sort the list in ascending order
        select_sort();

        if(isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {

            //if first node is greater than newNode
            if(head->data > newNode->data)
            {
                //put newNode in front of list
                push_front(newNode->data);
            }

            else
            {
                //set current to head
                Node<E> *current = head;
                //set tail to node after head
                tail = current->next;

                //continue to traverse node if tail value is less than newNode
                while(tail->data < newNode->data && tail->next != NULL)
                {
                    //traverse current pointer
                    current = current->next;
                    //traverse tail pointer
                    tail = tail->next;
                }

                //tail is pointing at end of list and less than new node
                if(tail->data < newNode->data && tail->next == NULL)
                {
//                    push_back(newNode->data);
                    //set current next to point to newNode
                    tail->next = newNode;
                    current = current->next;
                    tail = tail->next;
                }

                //tail is greater than new node data and not at end of list
                else if(tail->data > newNode->data)
                {
                    newNode->next = tail;
                    current->next = newNode;
                    current = newNode;
                }
            }
        }
    }

    /**********************************************************
    *
    *  Method remove_duplicates(): Class LinkedList
    *  _________________________________________________________
    *  This method removes all values (actually removes the nodes
    *    that contain the value) that are duplicates of a value
    *    that already exists in the list. Always remove the later
    *    duplicate, not the first instance of the duplicate.
    *  _________________________________________________________
    *  PRE-CONDITIONS
    *  none
    *
    *  POST-CONDITIONS
    *  This function sorts the list into ascending order using the
    *    selection sort algorithm
    ***********************************************************/
    void remove_duplicates()
    {
        Node<E> *duplicate_ptr = NULL;  //pointer to point to duplicate node
        Node<E> *prev_ptr = head;  //pointer to point to node before duplicate node
        Node<E> *remove_ptr = NULL;  //pointer to point to node to be removed

        //sort list in ascending order
        select_sort();

        //if list is empty, do nothing
        if(isEmpty())
        {
            return;
        }

        else
        {
            //point to node to be compared to rest of list
            for(Node<E> *current = head; current != NULL; current = current->next)
            {
                //set prev pointer to current
                prev_ptr = current;
                //set duplicate pointer to current next
                duplicate_ptr = current->next;

                //find if duplicate exists
                while(duplicate_ptr != NULL)
                {

                    //last duplicate node reached
                    if(duplicate_ptr->data == current->data)
                    {
                        remove_ptr = duplicate_ptr;

                        //only one duplicate left
                        if(duplicate_ptr == tail)
                        {
                            duplicate_ptr = NULL;
                            prev_ptr->next = NULL;
                            tail = prev_ptr;
                            delete remove_ptr;
                        }

                        //more than one duplicate left
                        else
                        {
                            duplicate_ptr = duplicate_ptr->next;
                            prev_ptr->next = remove_ptr->next;
                            delete remove_ptr;
                        }
                    }

                    else
                    {
                        prev_ptr = prev_ptr->next;
                        duplicate_ptr = duplicate_ptr->next;
                    }

                }

            }
        }
    }


private:
    int countNodes( Node<E> *ptr ) const
    {
        if(ptr == NULL)
        {
            return 0;
        }

        else
        {
            return 1 + countNodes(ptr->next);
        }
    }

    E addNodes( Node<E> *ptr ) const
    {
        if(ptr == NULL)
        {
            return 0;
        }

        else
        {
            return ptr->data + addNodes(ptr->next);
        }
    }


};

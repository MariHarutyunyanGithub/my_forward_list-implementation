template <typename T>
FList<T>::FList() : head(nullptr), itemCount(0){}

template<typename T>
FList<T>::FList(const T& anItem) : itemCount(1)
{
    head->setItem(anItem);
}

template<typename T>
FList<T>::FList(const FList& other) :
            itemCount{other.getItemCount()}
{
    if (other.getHead() != nullptr) {
        Node<T>* tmphead = head;
        for (int i{}; i < itemCount; ++i) {            
            head->setItem(other.getHead()->getItem()); 
            head = head->getNext();  
            other.setHead(other.getHead()->getNext());          
        }
        head = tmphead;
        tmphead = nullptr;
    }
}

template<typename T>
FList<T>::FList(const FList&& other) :
            itemCount{other.itemCount}
{
    if (other.getHead() != nullptr) {
       head = other.getHead();
       other.setHead(nullptr);
    }
}

template<typename T>        
FList<T>::~FList()  
{
    head = nullptr;
}  

template<typename T>
FList<T>& FList<T>::operator=(FList& other)
{
    if (head == other.getHead()) {
        return *this;
    }
    if (other.getHead() != nullptr) {
        itemCount = other.getItemCount();
        Node<T>* tmphead = head;   
        for (int i{}; i < itemCount; ++i) {            
            head->setItem(other.getHead()->getItem()); 
            head = head->getNext();  
            other.setHead(other.getHead()->getNext());          
        }
        head = tmphead;
        tmphead = nullptr;
    }
    return *this;
}

template<typename T>
FList<T>& FList<T>::operator=(const FList&& other)
{
    if (head == other.getHead()) {
        return *this;
    }
    if (other.getHead() != nullptr) {
        itemCount = other.getItemCount();   
        head = other.getHead();
        other.setHead(nullptr);
    }
    return *this;
}

template<typename T>
FList<T>& FList<T>::operator+(const FList& other)
{
    if (other.getHead() == nullptr) {
        return *this;
    }
    Node<T>* tmphead = head;
    itemCount = itemCount > other.getItemCount() ? itemCount : other.getItemCount();
    while ((head != nullptr) && (other.getHead() != nullptr)) {
        head->setItem(head->getItem() + other.getHead()->getItem());
        head = head->getNext();  
        other.setHead(other.getHead()->getNext()); 
    }
    if (head == nullptr) {
        head = other.getHead()->getNext();
    }
    head = tmphead;
    tmphead = nullptr;
    return *this;
}

template<typename T>
FList<T>& FList<T>::operator+=(const FList& other)
{
    if (other.getHead() == nullptr) {
        return *this;
    }
    if (head == nullptr) {
        head = other.getHead();
        itemCount = other.getItemCount();
        return *this;
    }
    itemCount += other.getItemCount();
    Node<T>* tmphead = head;
    while (head != nullptr) {
        head = head->getNext();
    }
    head->setNext(other.getHead());
    head = tmphead;
    tmphead = nullptr;
    return *this;
}

template<typename T>
bool FList<T>::insert(int position, const T& entry)
{
    bool ableToInsert = (position >= 1) && (position <= itemCount + 1);
    if (ableToInsert) {
        Node<T>* newNodePtr = new Node<T>(entry);
        if (position == 1) {
            newNodePtr->setNext(head);
            head = newNodePtr;
        }
        else {
            Node<T>* tmpPtr  = head;
            for (int i{1}; i < position; ++i) {
                head = head->getNext();
            }
            Node<T>* tmp = head->getNext();
            head->setNext(newNodePtr);
            newNodePtr->setNext(tmp);
            head = tmpPtr;
        }
        itemCount++;
    }
    return ableToInsert;
}

template<typename T>
FList<T>& FList<T>::push_front(const T& entry)
{
    Node<T>* newNodePtr = new Node<T>(entry);
        if (head == nullptr) {
            head = newNodePtr;
            newNodePtr->setNext(nullptr);
        }
        else {
            insert(1,entry);
        }
    itemCount++;
    return *this;
}

template<typename T>
bool FList<T>::remove_at(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount + 1);
    if (ableToRemove) {
        if (itemCount == 1) {
            head = nullptr;
        }
        else {
            Node<T>* tmphead = head;
            for (int i{1}; i < position; ++i) {
                head = head->getNext();
            }
            Node<T>* tmpPtr = head->getNext();
            head->setNext(head->getNext()->getNext());
            tmpPtr = nullptr;
            head = tmphead;
        }
        --itemCount;
    }
    return ableToRemove;
}

template<typename T>
bool FList<T>::isEmpty() const
{
    return !(itemCount);
}

template<typename T>
void FList<T>::clear()
{
    itemCount = 0;
    head = nullptr;
}

template<typename T>
T FList<T>::getEntry(int position)
{
    bool ableToGet = (position >= 1) && (position <= itemCount + 1);
    if (ableToGet) {
        Node<T>* tmphead = head;
        for (int i{1}; i <= position; ++i) {
            head = head->getNext();
        }
        T item = head->getItem();
        head = tmphead;
        tmphead = nullptr;
        return item;
    }
    throw "bad position";
}

template<typename T>
void FList<T>::setEntry(int position, const T& entry)
{
    bool ableToSet = (position >= 1) && (position <= itemCount + 1);
    if (ableToSet) {
        Node<T>* tmphead = head;
        for (int i{1}; i <= position; ++i) {
            head = head->getNext();
        }
        head->setItem(entry);
        head = tmphead;
        tmphead = nullptr;
    }
}

template <typename T>
Node<T>* FList<T>::getHead() const
{
    return head;
}

template<typename T>
void FList<T>::setHead(Node<T>* newPtr)
{
    head = newPtr;
}


template<typename T>
int FList<T>::getItemCount() const
{
    return itemCount;
}

template<typename T>
void FList<T>::setItemCount(int count)
{
    itemCount = count;
}
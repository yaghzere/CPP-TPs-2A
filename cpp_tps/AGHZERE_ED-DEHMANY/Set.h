#ifndef SET_H
#define SET_H

// template<typename T> class Set;

// template<typename T>
// Set<T> image(const Set<T> & set, T (*function)(T));



template<typename T>
class Set{
public:

  Set();

  Set(T x);

  inline void insert(T x);

  inline bool contains(T x) const;

  inline void remove(T x);


  std::ostream & flush(std::ostream & out) const{
    Node * n = list;
    while(n){
      out << n->getValue();
      out << " --> ";
      n = n->getNext();
    }
    return out;
  }


  Set(const Set<T> & other);

  void clear();

  Set & operator=(Set<T> & s){
    if(this == &s){
      return *this;
    }
    list = s.list;
    return *this; 
  }

  Set operator|(const Set<T> & s2){
    Node * n = this->list , * m = s2.list;
    Set<T> s;
    while(n){
      s.insert(n->getValue());
      n = n->getNext();
    }
    while(m){
      s.insert(m->getValue());
      m = m->getNext();
    }
    return s;
  }


  Set operator&(const Set<T> & s2){
    Node * n = this->list;
    Set<T> s;
    while(n){
      if(s2.contains(n->getValue())){
        s.insert(n->getValue());
      }
      n = n->getNext();
    }
    return s;
  } 

  friend Set operator-(const Set<T> & s1, const Set<T> & s2){
    Node * n = s1.list;
    Set<T> s;
    while(n){
      if(!s2.contains(n->getValue())){
        s.insert(n->getValue());
      }
      n = n->getNext();
    }
    return s;
  }

  Set operator^(const Set<T> & s2){
    return ((*(this)-s2) | (s2-*(this)));
  }

  inline Set singleton(T x);

  bool operator==(const Set<T> & b){
    Node * n = this->list;
    while(n){
      if(!b.contains(n->getValue())){
        return false;
      }
      n = n->getNext();
    }

    n = b.list;

    while(n){
      if(!this->contains(n->getValue())){
        return false;
      }
      n = n->getNext();
    }

    return true;
  }

  bool operator<( const Set<T> & b){
    Node * n = list;
    while(n){
      if(!b.contains(n->getValue())){
        return false;
      }
      n = n->getNext();
    }
    return true;
  }
  
  // friend Set<T> image<>(const Set<T> & set, T (*function)(T));

  friend Set<T> image(const Set<T> & set, T (*function)(T)){
    Set<T> s;
    Node * n = set.list;
    while(n){
      s.insert(function(n->getValue()));
      n = n->getNext();
    }
    return s;
  }



private:

  class Node {
    public:
      Node(T value, Node * next = nullptr){
        this->value = value;
        this->next = next;
      }
      ~Node();
      T getValue() const{
        return value;
      }
      Node * getNext() const{
        return next;
      }
      void setNext(Node * next){
        this->next = next;
      }

    private:
      T value;
      Node * next;
  };

  Node * list = nullptr;
  
};

template<typename T>
Set<T>::Set(){

}

template<typename T>
Set<T>::Set(T x){
  list->value = x;
}

template<typename T>
void Set<T>::insert(T x){
  Node * n = new Node(x, list);
  list = n;
}

template<typename T>
bool Set<T>::contains(T x) const{
  Node * n = list;
  while(n != nullptr){
    if(n->getValue() == x) {
      return true;
    }
    n = n->getNext();
    
  }
  return false;
}


template<typename T>
void Set<T>::remove(T x){
  Node * n = list;
  if(n == list){
    if(n->getValue() == x){
      list = n->getNext();
      return;
    }
  }
  while(n){
    Node * tmp = n->getNext();
    if(tmp->getValue() == x){
      n->setNext(tmp->getNext());
      return;
    }
    n = n->getNext();
  }
  return;
}


template<typename T>
Set<T>::Set(const Set<T> & other){
  if(this == &other){
  return;
  }
  this->list = other.list;  
}

template<typename T>
void Set<T>::clear(){
  Node * n = list;
  while(list){
    list = list->getNext();
    n = nullptr;
  }
}


template<typename T>
Set<T> singleton(T x){
  Set<T> s;
  s.insert(x);
  return s;
}



template <typename T>
std::ostream & operator<<(std::ostream & out, const Set<T> & s){
  return s.flush(out);
}


// template<typename T>
// Set<T> image(const Set<T> & set, T (*function)(T)){
//   Set<T> s;
//   Node * n = set.list;
//   while(n){
//     s.insert(function(n->getValue()));
//     n = n->getNext();
//   }
//   return s;
// }



#endif // SET_H
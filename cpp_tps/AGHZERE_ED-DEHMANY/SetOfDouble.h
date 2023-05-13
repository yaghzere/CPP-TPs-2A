/** -*- mode: c++ -*-
 * @file   SetOfDouble.h
 * @author Sebastien Fourey
 *
 * @brief Declaration of the class SetOfDouble
 */
#ifndef SETOFDOUBLE_H
#define SETOFDOUBLE_H

#include <iostream>
#include <ostream>

class SetOfDouble {

public:
  /**
   * Construct an empty set {}
   */
  SetOfDouble();

  /**
   * Construct a singleton {x}
   */
  SetOfDouble(double x);

  /**
   * Remove all elements from the set (i.e. make it empty)
   */
  void clear();

  ~SetOfDouble();

  bool isEmpty() const;

  /**
   * Send all elements to an output stream.
   *
   * @param out An output stream
   *
   * @return the output stream parameter
   */
  std::ostream & flush(std::ostream & out) const;

  /**
   * Check if a double belongs to the set
   *
   * @param x a double
   *
   * @return true if x belongs to the set
   */
  bool contains(double x) const;

  /**
   * Check inclusion
   *
   * @param e a set
   *
   * @return true if this set is included in the set e
   */
  bool isSubsetOf(const SetOfDouble & other) const;

  /**
   * Insert an element in the set (if not already present)
   *
   * @param x a double to be inserted
   */
  void insert(double x);

  /**
   * Remove an element from the set
   *
   * @param x a double to be removed from the set
   */
  void remove(double x);

  /**
   * Insert all elements into another set
   *
   * @param other another set
   */
  void insertInto(SetOfDouble & other) const;

  /**
   * Remove this set from another set (i.e., other=other-this).
   *
   * @param other a set
   */
  void removeFrom(SetOfDouble & other) const;

  /**
   * Assigment operator
   *
   * @param other a set
   *
   * @return a reference to this
   */
  SetOfDouble & operator=(const SetOfDouble & other);

  /**
   * Copy constructor
   *
   * @param other a set
   */
  SetOfDouble(const SetOfDouble & other);

  /**
   * @brief Compute the image of a set by a function
   */
  friend SetOfDouble image(const SetOfDouble & set, double (*function)(double));

private:
  class Node {
  public:
    Node(double value, Node * next = nullptr);
    ~Node();
    double getValue() const;
    Node * getNext() const;
    void setNext(Node * next);

  private:
    double value;
    Node * next;
  };

  Node * list;

  /**
   * Recursive method to remove the first occurence of a double
   * from a linked list
   *
   * @param list a linked list of nodes
   * @param x an element to be removed
   *
   * @return the list without x
   */
  static Node * remove(Node * list, double x);
};

/**
 * Operator << for sets of doubles
 *
 * @param out an output stream
 * @param s a set of doubles
 *
 * @return the output stream
 */
std::ostream & operator<<(std::ostream & out, const SetOfDouble & s);

/**
 * Create a singleton with a given element
 *
 * @param x a double
 *
 * @return the singleton {x}
 */
SetOfDouble singleton(double x);

/**
 * Create an empty set
 *
 * @return the empty set {}
 */
SetOfDouble emptySet();

/**
 * Check if two sets are equal
 *
 * @param a a set
 * @param b a set
 * @return true if a=b (i.e., a is in b and b is in a), otherwise false
 */
bool operator==(const SetOfDouble & a, const SetOfDouble & b);

/**
 * Check if a set in included in another one.
 *
 * @param a a set
 * @param b a set
 * @return true if a is included in b
 */
bool operator<(const SetOfDouble & a, const SetOfDouble & b);

/**
 * Check if a set contains another one.
 *
 * @param a a set
 * @param b a set
 * @return true if a contains b
 */
bool operator>(const SetOfDouble & a, const SetOfDouble & b);

/**
 * Union of two sets (Logical OR)
 *
 * @param a a set
 * @param b a set
 * @return a union b.
 */
SetOfDouble operator|(const SetOfDouble & a, const SetOfDouble & b);

/**
 * Difference between two sets
 *
 * @param a a set
 * @param b a set
 * @return a minus b (elements of a that are not in b)
 */
SetOfDouble operator-(const SetOfDouble & a, const SetOfDouble & b);

/**
 * Symmetric Serence between two sets (XOR). Elements that
 * are in any of the two sets, but not in both of them.
 *
 * @param a a set
 * @param b a set
 * @return (a minus b) union (b minus a)
 */
SetOfDouble operator^(const SetOfDouble & a, const SetOfDouble & b);

/**
 * Intersection between two sets (Logical AND)
 *
 * @param a a set
 * @param b a set
 * @return intersection between a and b
 */
SetOfDouble operator&(const SetOfDouble & a, const SetOfDouble & b);

#endif // SETOFDOUBLE_H

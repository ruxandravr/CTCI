#ifndef CTCI_S_NODE_H
#define CTCI_S_NODE_H

template <typename V>
class SNode
{
public:
  V value;
  SNode<V> *next;

  SNode() =  delete;
  ~SNode() = default;
  SNode(V value);
  SNode<V>(const SNode<V> &other);
  SNode<V>& operator=(const SNode<V> &other);
  bool equals(const SNode<V> &node);

};

template<typename V>
SNode<V>::SNode(V value)
{
  this->value = value;
  this->next = nullptr;
}

template<typename V>
SNode<V>::SNode(const SNode<V> &other)
{
  this->value = other.value;
  this->next = other.next;
}

template<typename V>
SNode<V>& SNode<V>::operator=(const SNode<V> &other)
{
  this->value = other.value;
  this->next = other.next;

  return *this;
}

template<typename V>
bool SNode<V>::equals(const SNode<V> &node)
{
  return value == node.value;
}

#endif
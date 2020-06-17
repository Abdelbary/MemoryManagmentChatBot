#include <iostream>

#include "graphedge.h"
#include "graphnode.h"

GraphEdge::GraphEdge(int id) {
  this->_id = id;
  this->_childNode = nullptr;
  this->_parentNode = nullptr;
  this->_keywords = {};
}

GraphEdge::GraphEdge(GraphEdge &source) {
  this->_childNode = source._childNode;
  this->_parentNode = source._parentNode;
  this->_id = source._id;
  this->_keywords = source._keywords;
}

GraphEdge::GraphEdge(GraphEdge &&source)  {
  this->_childNode = source._childNode;
  this->_parentNode = source._parentNode;
  this->_id = source._id;
  this->_keywords = std::move(source._keywords);

  source._childNode = nullptr;
  source._parentNode = nullptr;
  source._id = 0;
}

GraphEdge& GraphEdge::operator=(GraphEdge const& source) {
  std::cout << "GraphEdge Copy Assignment Operator" << std::endl;

  if (this == &source) {
    return *this;
  }

  // shallow copy of data handles
  this->_childNode = source._childNode;
  this->_parentNode = source._parentNode;
  this->_id = source._id;
  this->_keywords = source._keywords;

  return *this;
}

GraphEdge& GraphEdge::operator=(GraphEdge &&source)  {
  std::cout << "GraphEdge Move Assignment Operator" << std::endl;

  if (this == &source) {
    return *this;
  }

  // transfering data handles
  this->_childNode = source._childNode;
  this->_parentNode = source._parentNode;
  this->_id = source._id;
  this->_keywords = std::move(source._keywords);

  // releasing data handles
  source._childNode = nullptr;
  source._parentNode = nullptr;
  source._id = 0;

  return *this;
}

void GraphEdge::SetChildNode(GraphNode *childNode) { _childNode = childNode; }

void GraphEdge::SetParentNode(GraphNode *parentNode) {
  this->_parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token) { _keywords.push_back(token); }
#include <iostream>
#include <memory>

#include "graphnode.h"
#include "graphedge.h"
#include "chatlogic.h"

GraphNode::GraphNode(int id) { _id = id; }

<<<<<<< HEAD
GraphNode::~GraphNode(){}
=======
GraphNode::~GraphNode() {}

GraphNode::GraphNode(GraphNode&& source)  {
  this->_chatBot = source._chatBot;
  this->_childEdges = std::move(source._childEdges);
  this->_parentEdges = std::move(source._parentEdges);
  this->_id = source._id;
  this->_answers = std::move(source._answers);

  // release handles
  source._id = -1;
}
>>>>>>> 5833f6ac86b85811d3caf8c35af1931ff7ba58cd

GraphNode& GraphNode::operator=(GraphNode&& source)  {
  if (this == &source) {
    return *this;
  }

  this->_chatBot = source._chatBot;
  this->_childEdges = std::move(source._childEdges);
  this->_parentEdges = std::move(source._parentEdges);
  this->_id = source._id;
  this->_answers = std::move(source._answers);

  // release handles;
  source._id = -1;

  return *this;
}


<<<<<<< HEAD
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
=======

void GraphNode::AddToken(const std::string& token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge* edge) {
  this->_parentEdges.push_back(edge);
>>>>>>> 5833f6ac86b85811d3caf8c35af1931ff7ba58cd
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  this->_childEdges.push_back(std::move(edge));
}
<<<<<<< HEAD


GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    return _childEdges[index];
=======

void GraphNode::MoveChatbotHere(ChatBot &&chatbot) {
  this->_chatBot = std::move(chatbot);
  this->_chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);
  this->_chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  return _childEdges[index].get();
>>>>>>> 5833f6ac86b85811d3caf8c35af1931ff7ba58cd
}
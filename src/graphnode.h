#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "chatbot.h"

// forward declarations
class GraphEdge;

class GraphNode {
 private:
  // data handles (owned)
  std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent
  ChatBot _chatBot;

  // data handles (not owned)
  std::vector<GraphEdge *> _parentEdges;  // edges to preceding nodes

  // proprietary members
  int _id;
  std::vector<std::string> _answers;
 

 public:
  // constructor / destructor
  GraphNode(int id);
  ~GraphNode();
  GraphNode(GraphNode && source) ;
  GraphNode& operator=(GraphNode&& source) ;
  GraphNode(GraphNode const& source) = delete;
  GraphNode& operator=(GraphNode const& source) = delete;
  // getter / setter
  int GetID() { return _id; }
  int GetNumberOfChildEdges() { return _childEdges.size(); }
  GraphEdge *GetChildEdgeAtIndex(int index);
  std::vector<std::string> GetAnswers() { return _answers; }
  int GetNumberOfParents() { return _parentEdges.size(); }

  // proprietary functions
  void AddToken(const std::string& token);  // add answers to list
  void AddEdgeToParentNode(GraphEdge* edge);
  void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);
  void MoveChatbotHere(ChatBot &&chatbot);
  void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */
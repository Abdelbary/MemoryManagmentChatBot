#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <string>
#include <vector>

#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

<<<<<<< HEAD
class ChatLogic
{
private:


    // data handles (owned)
    std::vector<std::unique_ptr<GraphNode> > _nodes;
    std::vector<std::unique_ptr<GraphEdge> > _edges;



    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ChatLogic(ChatLogic const & source) = delete;
    ChatLogic(ChatLogic const &&source);
    ~ChatLogic();

    ChatLogic & operator=(ChatLogic const &source) = delete;
    ChatLogic & operator=(ChatLogic const &&source);
    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
=======
class ChatLogic {
 private:

  // data handles (owned)
  std::vector<std::unique_ptr<GraphNode>> _nodes;

  // data handles (not owned)
  GraphNode *_currentNode;
  ChatBot *_chatBot;
  ChatBotPanelDialog *_panelDialog;

  // proprietary type definitions
  typedef std::vector<std::pair<std::string, std::string>> tokenlist;



  // proprietary functions
  template <typename T>
  void AddAllTokensToElement(const std::string& tokenID, tokenlist &tokens,
                             T &element);

 public:
  // constructor / destructor
  ChatLogic();
  ~ChatLogic();
  ChatLogic(ChatLogic const& source) = delete;
  ChatLogic& operator=(ChatLogic const& source) = delete;
  ChatLogic(ChatLogic && source);
  ChatLogic& operator=(ChatLogic&& source);

  // getter / setter
  void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
  void SetChatbotHandle(ChatBot *chatbot);

  // proprietary functions
  void LoadAnswerGraphFromFile(const std::string& filename);
  void SendMessageToChatbot(const std::string& message);
  void SendMessageToUser(const std::string& message);
  wxBitmap *GetImageFromChatbot();
>>>>>>> 5833f6ac86b85811d3caf8c35af1931ff7ba58cd
};

#endif /* CHATLOGIC_H_ */
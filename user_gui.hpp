#ifndef __USER_GUI_HPP__
#define __USER_GUI_HPP__


bool show_demo_window = true;
bool show_another_window = false;

EM_JS(void, alert, (),
{
  alert("Hello alert!");
});


char text[4096];
bool read_only = false;

void user_gui(void)
{
  // 1. Show a simple window.
  // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
  {
      static float f = 0.0f;
      static int counter = 0;
      ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
      ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
      ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

      ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our windows open/close state
      ImGui::Checkbox("Another Window", &show_another_window);

      if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
          counter++;
      ImGui::SameLine();
      ImGui::Text("counter = %d", counter);

      ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
  }

  //std::cout << "2nd window" << std::endl;

  // 2. Show another simple window. In most cases you will use an explicit Begin/End pair to name your windows.
  if (show_another_window)
  {
      ImGui::Begin("Another Window", &show_another_window);
      ImGui::Text("Hello from another window!");
      if (ImGui::Button("Close Me"))
          show_another_window = false;
      ImGui::End();
  }

  // 3. Show the ImGui demo window. Most of the sample code is in ImGui::ShowDemoWindow(). Read its code to learn more about Dear ImGui!
  if (show_demo_window)
  {
      ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
      ImGui::ShowDemoWindow(&show_demo_window);
  }    
    
    ImGui::Begin("User Window");
    ImGui::Text("Hello from another window!");
    ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-1.0f, ImGui::GetTextLineHeight() * 16), ImGuiInputTextFlags_AllowTabInput | (read_only ? ImGuiInputTextFlags_ReadOnly : 0));    
    if (ImGui::Button("append"))
    {
        if((text[strlen(text) - 1] == '\n') || (text[strlen(text) - 1] == '\r'))
        {
            strcat(text,"Hello world!\n");
        }
        else
        {
            if(strlen(text) != 0)
                strcat(text,"\nHello world!\n");
            else
                strcat(text,"Hello world!\n");
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("clear"))
    {
        text[0]='\0';
    }
    ImGui::Separator();
    ImGui::Button("test");
    ImGui::End();
}


#endif//__USER_GUI_HPP__

#include <discordpp/discordpp.h>

#include <iostream>

int main() {

  // Replace YOUR_BOT_TOKEN with your bot's token

  discordpp::Bot bot("YOUR_BOT_TOKEN");

  bot.on_message_create = [&](discordpp::Message message) {

    // Check if the message starts with the command prefix "!"

    if (message.content.find("!") == 0) {

      // Split the message into command and arguments

      std::vector<std::string> words = discordpp::split(message.content, ' ');

      std::string command = words[0].substr(1);  // Remove the "!" prefix

      // Handle the "play" command

      if (command == "play") {

        if (words.size() < 2) {

          // If the command doesn't have any arguments, send an error message

          bot.create_message(message.channel_id, "Error: No song specified.");

          return;

        }

        // Join the rest of the message into a single string as the song name

        std::string song_name = discordpp::join(words, ' ', 1);

        // Send a message to the channel saying that the bot is searching for the song

        bot.create_message(message.channel_id, "Searching for `" + song_name + "`...");

        // TODO: Search for the song and play it

      }

    }

  };

  // Connect the bot to the Discord API

  bot.run();

  return 0;

}


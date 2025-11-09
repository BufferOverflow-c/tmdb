#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include <nlohmann/json.hpp>

#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

using json = nlohmann::json;

void getNowPlaying(std::string token);
void getPopular(std::string token);
void getTopRated(std::string token);
void getUpcoming(std::string token);

int main(int argc, char *argv[]) {
  if (argc < 5) {
    std::cerr << "Usage: tmdb-cli --type playing --token <access_token>"
              << std::endl;
    std::cerr << "Usage: tmdb-cli --type popular --token <access_token>"
              << std::endl;
    std::cerr << "Usage: tmdb-cli --type top --token <access_token>"
              << std::endl;
    std::cerr << "Usage: tmdb-cli --type upcoming --token <access_token>"
              << std::endl;
    return 1;
  }

  if (std::string(argv[2]) == "playing")
    getNowPlaying(argv[4]);
  else if (std::string(argv[2]) == "popular")
    getPopular(argv[4]);
  else if (std::string(argv[2]) == "top")
    getTopRated(argv[4]);
  else if (std::string(argv[2]) == "upcoming")
    getUpcoming(argv[4]);

  return 0;
}

void getNowPlaying(std::string token) {
  curlpp::Cleanup cleanup;
  curlpp::Easy request;
  std::ostringstream response;
  std::list<std::string> headers;
  headers.emplace_back("Authorization: Bearer " + token);
  headers.emplace_back("accept: application/json");
  request.setOpt(new curlpp::options::Url(
      "https://api.themoviedb.org/3/discover/"
      "movie?include_adult=false&include_video=false&language=en-US&page=1&"
      "sort_by=popularity.desc&with_release_type=2|3&release_date.gte={min_"
      "date}&release_date.lte={max_date}"));
  request.setOpt(new curlpp::options::HttpHeader(headers));
  request.setOpt(new curlpp::options::WriteStream(&response));
  request.perform();

  auto data = json::parse(response.str());
  std::cout << data.dump(2) << std::endl;
}

void getPopular(std::string token) {
  curlpp::Cleanup cleanup;
  curlpp::Easy request;
  std::ostringstream response;
  std::list<std::string> headers;
  headers.emplace_back("Authorization: Bearer " + token);
  headers.emplace_back("accept: application/json");
  request.setOpt(new curlpp::options::Url(
      "https://api.themoviedb.org/3/discover/"
      "movie?include_adult=false&include_video=false&language=en-US&page=1&"
      "sort_by=popularity.desc"));
  request.setOpt(new curlpp::options::HttpHeader(headers));
  request.setOpt(new curlpp::options::WriteStream(&response));
  request.perform();

  auto data = json::parse(response.str());
  std::cout << data.dump(2) << std::endl;
}

void getTopRated(std::string token) {
  curlpp::Cleanup cleanup;
  curlpp::Easy request;
  std::ostringstream response;
  std::list<std::string> headers;
  headers.emplace_back("Authorization: Bearer " + token);
  headers.emplace_back("accept: application/json");
  request.setOpt(new curlpp::options::Url(
      "https://api.themoviedb.org/3/discover/"
      "movie?include_adult=false&include_video=false&language=en-US&page=1&"
      "sort_by=vote_average.desc&without_genres=99,10755&vote_count.gte=200"));
  request.setOpt(new curlpp::options::HttpHeader(headers));
  request.setOpt(new curlpp::options::WriteStream(&response));
  request.perform();

  auto data = json::parse(response.str());
  std::cout << data.dump(2) << std::endl;
}

void getUpcoming(std::string token) {
  curlpp::Cleanup cleanup;
  curlpp::Easy request;
  std::ostringstream response;
  std::list<std::string> headers;
  headers.emplace_back("Authorization: Bearer " + token);
  headers.emplace_back("accept: application/json");
  request.setOpt(new curlpp::options::Url(
      "https://api.themoviedb.org/3/discover/"
      "movie?include_adult=false&include_video=false&language=en-US&page=1&"
      "sort_by=popularity.desc&with_release_type=2|3&release_date.gte={min_"
      "date}&release_date.lte={max_date}"));
  request.setOpt(new curlpp::options::HttpHeader(headers));
  request.setOpt(new curlpp::options::WriteStream(&response));
  request.perform();

  auto data = json::parse(response.str());
  std::cout << data.dump(2) << std::endl;
}

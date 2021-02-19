void PrintBusesForStop(map<string, vector<string>>& stops,const string& stop) {
  if (stops.count(stop) == 0) {
    cout << "No stop" << endl;
  } else {
    for (const string& bus : stops[stop]) {
      cout << bus << " ";
    }
    cout << endl;
  }
}
void PrintStopsForBus(map<string, vector<string>>& buses,map<string, vector<string>>& stops, const string& bus) {
  if (buses.count(bus) == 0) {
    cout << "No bus" << endl;
  } else {
    for (const string& stop : buses[bus]) {
      cout << "Stop " << stop << ": ";
      if (stops[stop].size() == 1) {
        cout << "no interchange";
      } else {
        for (const string& other_bus : stops[stop]) {
          if (bus != other_bus) {
            cout << other_bus << " ";
          }
        }
      }
      cout << endl;
    }
  }
}

void PrintAllBuses(const map<string, vector<string>>& buses) {
  if (buses.empty()) {
    cout << "No buses" << endl;
  } else {
    for (const auto& bus_item : buses) {
      cout << "Bus " << bus_item.first << ": ";
      for (const string& stop : bus_item.second) {
        cout << stop << " ";
      }
      cout << endl;
    }
  }
}


int main() {
  int Q;
  cin >> Q;
  map<string, vector<string>> buses, stops;
  string command;
  for (int i = 0; i < Q; ++i) {
    cin >> command;
    if (command == "NEW_BUS") {
      string bus;
      cin >> bus;
      int stop_count;
      cin >> stop_count;
      buses[bus].resize(stop_count);
      for (string& stop : buses[bus]) {
        cin >> stop;
        stops[stop].push_back(bus);
      }
    }else if (command == "BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      PrintBusesForStop(stops, stop);
    } else if (command == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;
      PrintStopsForBus(buses, stops, bus);
    } else if (command == "ALL_BUSES") {
      PrintAllBuses(buses);
    }
  }
  return 0;
}

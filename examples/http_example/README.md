# ElasticSearch HTTP example

In this example, the application in `main.cc` initializes a connection to an ElasticSearch instance and writes a basic JSON object to it. Before we can run the test, we need to set up an elastic search instance locally. Follow the steps below to do this:

## Setting up ElasticSearch
1. Download elasticsearch from the main homepage then unzip it.
2. In a terminal, navigate to its bin/ folder and start elasticsearch by typing `./elasticsearch`.
3. Wait for the outputs to stop, then locate the line where it says what port it is using. Typically, it is port 9200.

With elasticsearch running, this example can now be used. To run this example, do the following steps:

1. Run cmake from the root directory. This is done my simply calling `cmake .`
2. Navigate to this folder by calling `cd examples/http_example` and build the project by calling `make`
3. Run the project by calling `./example_http`. When it asks for the port, enter the port that elasticsearch is using from before.
4. Look at the response code. If the response code looks something like 
   
`{
  "_index" : "logs",
  "_type" : "_doc",
  "_id" : "Z1xu4XUBspZtZHoKQbJD",
  "_version" : 1,
  "result" : "created",
  "_shards" : {
    "total" : 2,
    "successful" : 1,
    "failed" : 0
  },
  "_seq_no" : 4,
  "_primary_term" : 6
}`


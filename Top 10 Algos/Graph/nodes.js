WEBVTT
Hey guys in this video I just want to talk a little bit about what react is in why you would use it
as opposed to using like just vanilla javascript so 
//react is a client side javascript library and
when I say 
client side what I mean is it runs on the client machine or the user's machine in the browser
as opposed to on the server although it is possible to render react on the server and react as created
and
maintained by Facebook so it does have the best of the best in terms of developers behind it.
// It's used to build front end applications and user interfaces.
// It allows us to make user interfaces more dynamic and separate things into components.
So when we use server side rendering of templates in let's say like pHp or something like that we're
very limited to functionality because once the front end is painted into the browser that's it we can't
really do anything else but with 
//react we have something called a virtual dom where we can dynamically
update different parts of the dom or different parts of the Web site or application without having to
refresh the page.
So if we have a form component where we can submit something or even if we just start typing in a field
we can make something else happen in another component without even reloading the page and we can make
HTTP request to backend servers and get and display data without reloading the page.
And yes we can do this with vanilla javascript but it's ten times more difficult and reacts not only
simplifies this but 
it gives us organization by letting us make anything on the page we want into a
// component also components have their own state their own methods their own functionality and we'll
talk more about this stuff later
react is also often referred to as the V in MVC.
Now MVC is a design pattern called model view controller where the model deals with the data the controller
deals with getting the data from the model and sending it to The View and The View is responsible for
displaying to the user.
OK so react is basically the V The View part.
Now a lot of people will call react a framework and that's not technically wrong.
I do it all the time.
And the reason for that is it's a direct competitor of other frameworks like angular vwe MBR J.S..
These are all frameworks and re-act is actually is actually at the top.
When you compare all those the reason that it's called the libraries because it's missing a few key
things that most frameworks include one of which is a router in case of angular and Vwe.
They have their own routing mechanism and react doesn't have it at its core but it has something there's
something called react router that you can simply install with NPM and then you have a router.
Same thing with a HTTP, angular has its own HTTP client to make requests with react you can use the fetch
API which is just a native browser based you know it works in every browser.
You also have axios which you can install which is a really small HTTP library so problem solved there.
So that's why it's not technically called a framework because it doesn't include a couple key features.
Jquery is a javascript library which is used for many different things and react is a completely
different animal than Jquery.
It's nothing like it.
// It's much much closer to angular and view in amber.
// And those are those are frameworks those are not libraries.
// OK then you also have state managers like Redux which belong to the react ecosystem to make it even
// more powerful and we'll be looking at redux later on.
So why should you learn react you know javascript you know how to manipulate the Dom etc that may be
fine for like really tiny projects but to build a complete front end application that communicates with
the back backend in plain javascript.
It would be ten times as difficult and it would be much much less organized and a lot more code at that
// React gives you complete organization of yours you use your interfaces through components not just rendering
// and displaying them but gives them state data and properties that are attached to them.
// OK react components are reusable within the same project and in some cases in other projects and it makes
// your app more scalable more efficient.
If you want to add more components and functionality it makes it very easy to do.
And it's also lighter than most other frameworks.
I don't like picking favorites.
I do like angular as well of course on angular.
It includes more in its core but it's also much heavier and a lot of times you don't even need the stuff
that it includes.
And then most importantly re-act is the hottest technology in javascript right now.
There's there's loads of jobs looking for re-act devs.
All right so that's the gist of what re-act is you should learn it.
Now let's jump in let's get our environments set up so that we can start to learn all about react and
redux.

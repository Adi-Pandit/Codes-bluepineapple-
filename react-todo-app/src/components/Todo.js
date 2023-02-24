import React, { useState } from "react";

export default function Todo() {
  const [task, setTask] = useState("");
  const [data, setData] = useState([]);

  const handleOnChange = (event) => {
    setTask(event.target.value);
  }

  const addTask = () => {

    if(!task) {
      alert('Enter an item');
      return;
    }
    const taskList = {
      id: Math.floor(Math.random()*1000),
      value: task
    }
    setData(oldList => [...oldList, taskList]);
    setTask('');
    console.log(data);
  };

  function deleteTask(id) {
    const newArray = data.filter(element => element.id !== id);
    setData(newArray);
    console.log(newArray);
  }

  return (
    <div>
      <h1>Todo List</h1>
        <div className="row">
          <input type="text" size="50" value={task} onChange={handleOnChange} />
          <button type="submit" onClick={addTask} style={{ marginLeft: "10px" }}>
            Add
          </button>

          <thead>
            <tr>
              <th>Task</th>
              <th>Operation</th>
            </tr>
          </thead>
          <tbody>
            {data.map(element => {
              return(
                <tr> 
                  <td key={element.id}>{element.value}</td>   
                  <td><button onClick={()=>deleteTask(element.id)}>Delete</button></td>
                </tr>
              )
            })}
          </tbody>
        </div>
    </div>
  );
}

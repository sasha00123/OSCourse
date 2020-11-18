package university.innopolis.oscourseweek15;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    ListView mTasksListView;
    ArrayAdapter<String> mAdapter;
    ArrayList<String> taskList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTasksListView = (ListView) findViewById(R.id.list_todo);

        mAdapter = new ArrayAdapter<>(this, R.layout.todo_item, R.id.task_title, taskList);
        mTasksListView.setAdapter(mAdapter);
    }

    public void showAddDialog() {
        final EditText taskEditText = new EditText(this);
        AlertDialog dialog =  new AlertDialog.Builder(this)
                .setTitle("Add a new task")
                .setMessage("What do you want to do next?")
                .setView(taskEditText)
                .setPositiveButton("Add", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        String task = String.valueOf(taskEditText.getText());
                        Log.d("MainClass", "Task to add: " + task);
                        addItem(task);
                    }
                })
                .setNegativeButton("Cancel", null)
                .create();
        dialog.show();
    }

    public void removeButtonClickListener(View view) {
        ViewGroup task = (ViewGroup) view.getParent();
        removeItem(((TextView) task.getChildAt(0)).getText().toString());
    }

    private void addItem(String itemText) {
        taskList.add(itemText);
        mAdapter.notifyDataSetChanged();
    }

    private void removeItem(String itemText) {
        taskList.remove(itemText);
        mAdapter.notifyDataSetChanged();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case R.id.action_add_task:
                Log.d("MainClass", "Add a new task");
                showAddDialog();
                return true;
            default:
                    return super.onOptionsItemSelected(item);
        }
    }
}
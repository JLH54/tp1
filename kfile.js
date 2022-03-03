let project = new Project('TP1_Julien');

project.kore = false;
project.cmd = true;

project.addFile('Sources/**');
project.setDebugDir('./Deployment');

resolve(project);
